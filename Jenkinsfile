pipeline{
    agent any
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
                sh '(git diff-tree --no-commit-id --name-only -r $(git symbolic-ref --short HEAD)) | grep \'.*[\\.cpp|\\.h|\\.hpp|\\.cxx]\' | xargs -n 1 clang-format --sort-includes --style=LLVM -i'
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
                sh 'git commit -m \"Jenkins fix: $(git show-branch --no-name $(git symbolic-ref --short HEAD))\"'
                sh 'git push --set-upstream origin $(git symbolic-ref --short HEAD)'
            }
        }
    }
}
