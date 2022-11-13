void setBuildStatus(String message, String state, String my_repo) {
  step([
      $class: "GitHubCommitStatusSetter",
      reposSource: [$class: "ManuallyEnteredRepositorySource", url: my_repo],
      contextSource: [$class: "ManuallyEnteredCommitContextSource", context: "ci/jenkins/build-status"],
      errorHandlers: [[$class: "ChangingBuildStatusErrorHandler", result: "UNSTABLE"]],
      statusResultSource: [ $class: "ConditionalStatusResultSource", results: [[$class: "AnyBuildResult", message: message, state: state]] ]
  ]);
}

pipeline{
    agent any
    options {
        timestamps()
    }
    environment {
        GitUrl = """${sh(
            returnStdout: true,
            script: 'git config --get remote.origin.url'
        )}""" 
    }
    triggers {
        githubPush()
    }
    stages {
        stage("Init docker"){
            steps {
                sh 'docker-compose pull'
                sh 'docker-compose build --pull'
                sh 'docker-compose up -d'
            }
        }
        stage("Formating"){
            steps {
                echo 'Formating src'
                sh 'docker-compose run maker_cpp find src -regex \'.*\\.\\(cpp\\|hpp\\|h\\|cxx\\)\' -exec clang-format --sort-includes --style=LLVM -i {} \\;'
                echo 'Formating tests'
                sh 'docker-compose run maker_cpp find tests -regex \'.*tst.*\\.\\(cpp\\|hpp\\|h\\|cxx\\)\' -exec clang-format --sort-includes --style=LLVM -i {} \\;'
            }
        }
        stage("Compile"){
            steps {
                sh 'docker-compose run maker_cpp cmake ./'
                sh 'docker-compose run maker_cpp make'
            }
        }
        stage("Create documentation"){
            steps {
                sh 'docker-compose run maker_cpp doxygen'
            }
        }
        stage("Tests"){
            stages {
                stage("CppCheck"){
                    steps {
                        sh 'docker-compose run maker_cpp cppcheck --enable=all --suppress=missingInclude --std=c++17 --library=qt --quiet --verbose --template="[{severity}][{id}] {message} \n\t> {callstack}\n" src/'
                    }
                }
                stage("Unit Tests"){
                    steps {
                        sh 'docker-compose run maker_cpp ./tests/tests'
                    }
                }
            }
        }
        stage("Down docker"){
            steps {
                sh 'docker-compose down --remove-orphans'
            }
        }
        stage("Git add commit push"){
            when {
                expression {
                    return "${sh(returnStdout: true, script: 'git status --short')}";
                }
            }
            steps {
                sh 'git add .'
                sh 'git config --global user.email "ilya.kamckine@yandex.ru"'
                sh 'git config --global user.name "Jenkins"'
                sh 'git commit -m \"Jenkins fix: $(git show-branch --no-name $(git symbolic-ref --short HEAD))\"'
                sh 'git push --set-upstream origin $(git symbolic-ref --short HEAD)'
            }
        }
    }
    post {
        success {
            setBuildStatus("Build succeeded", "SUCCESS", "${env.GitUrl}");
        }
        failure {
            setBuildStatus("Build failed", "FAILURE", "${env.GitUrl}");
        }
    }
}
