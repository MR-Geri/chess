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
    environment {
        GitUrl = """${sh(
                returnStdout: true,
                script: 'git config --get remote.origin.url'
            )}""" 
        GitBranch = """${sh(
                returnStdout: true,
                script: 'git symbolic-ref --short HEAD'
            )}""" 
    }
    triggers {
        githubPush()
    }
    options {
        timestamps()
    }
    stages {
        stage("Formating"){
            when {
                anyOf {
                    changeset pattern: "src/.*\\.cpp", comparator: "REGEXP";
                    changeset pattern: "src/.*\\.h", comparator: "REGEXP";
                    changeset pattern: "src/.*\\.hpp", comparator: "REGEXP";
                    changeset pattern: "src/.*\\.cxx", comparator: "REGEXP";
                    changeset pattern: "tests/.*\\.cpp", comparator: "REGEXP";
                    changeset pattern: "tests/.*\\.h", comparator: "REGEXP";
                    changeset pattern: "tests/.*\\.hpp", comparator: "REGEXP";
                    changeset pattern: "tests/.*\\.cxx", comparator: "REGEXP";
                }
            }
            steps {
                sh 'git diff-tree --no-commit-id --name-only -r ${env.GitBranch} | grep \'.*[\\.cpp|\\.h|\\.hpp|\\.cxx]\' | xargs -n 1 clang-format --sort-includes --style=LLVM -i'
            }
        }
        // stage("CMAKE compile"){
        //     steps {
        //         cmake installation: 'InSearchPath'
        //         cmakeBuild buildType: 'Release', cleanBuild: true, installation: 'InSearchPath', steps: [[withCmake: true]]
        //     }
        // }
        // stage("MAKE compile"){
        //     steps {
        //         sh 'make'
        //     }
        // }
        stage("Documentation and Test"){
            parallel {
                stage("Create documentation"){
                    when {
                        anyOf {
                            changeset pattern: "src/.*\\.cpp", comparator: "REGEXP";
                            changeset pattern: "src/.*\\.h", comparator: "REGEXP";
                            changeset pattern: "src/.*\\.hpp", comparator: "REGEXP";
                            changeset pattern: "src/.*\\.cxx", comparator: "REGEXP";
                            changeset pattern: "tests/.*\\.cpp", comparator: "REGEXP";
                            changeset pattern: "tests/.*\\.h", comparator: "REGEXP";
                            changeset pattern: "tests/.*\\.hpp", comparator: "REGEXP";
                            changeset pattern: "tests/.*\\.cxx", comparator: "REGEXP";
                            changeset pattern: "README.md", comparator: "REGEXP";
                        }
                    }
                    steps {
                        sh 'doxygen'
                    }
                }
                stage("Tests"){
                    steps {
                        sh 'docker-compose down --remove-orphans'
                        sh 'docker-compose pull'
                        sh 'docker-compose build --pull'
                        sh 'docker-compose up -d'
                        sh 'docker-compose run maker_cpp ./tests/tests'
                    }
                }
            }
        }
        stage("Git add commit push"){
            when {
                anyOf {
                    changeset pattern: "src/.*\\.cpp", comparator: "REGEXP";
                    changeset pattern: "src/.*\\.h", comparator: "REGEXP";
                    changeset pattern: "src/.*\\.hpp", comparator: "REGEXP";
                    changeset pattern: "src/.*\\.cxx", comparator: "REGEXP";
                    changeset pattern: "tests/.*\\.cpp", comparator: "REGEXP";
                    changeset pattern: "tests/.*\\.h", comparator: "REGEXP";
                    changeset pattern: "tests/.*\\.hpp", comparator: "REGEXP";
                    changeset pattern: "tests/.*\\.cxx", comparator: "REGEXP";
                    changeset pattern: "README.md", comparator: "REGEXP";
                }
            }
            steps {
                sh 'git add .'
                sh 'git config --global user.email "ilya.kamckine@yandex.ru"'
                sh 'git config --global user.name "Jenkins"'
                sh 'git commit -m \"Jenkins fix: $(git show-branch --no-name ${env.GitBranch})\"'
                sh 'git push --set-upstream origin ${env.GitBranch}'
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
