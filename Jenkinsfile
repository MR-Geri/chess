pipeline{
    agent any
    options {
        timestamps()
    }
    stages {
        stage("CMAKE compile"){
            steps {
                cmake installation: 'InSearchPath'
                cmakeBuild buildType: 'Release', cleanBuild: true, installation: 'InSearchPath', steps: [[withCmake: true]]
            }
        }
        stage("MAKE compile"){
            steps {
                sh 'make'
            }
        }
        stage("Formating"){
            when {
                anyOf {
                    changeset pattern: ".*\\.cpp", comparator: "REGEXP"
                    changeset pattern: ".*\\.h", comparator: "REGEXP"
                    changeset pattern: ".*\\.hpp", comparator: "REGEXP"
                    changeset pattern: ".*\\.cxx", comparator: "REGEXP"
                }
            }
            steps {
                sh '(git diff-tree --no-commit-id --name-only -r $(git symbolic-ref --short HEAD)) | grep \'.*[\\.cpp|\\.h|\\.hpp|\\.cxx]\' | xargs -n 1 clang-format --sort-includes --style=LLVM -i'
            }
        }
        stage("Create documentation"){
            when {
                anyOf {
                    changeset pattern: ".*\\.cpp", comparator: "REGEXP"
                    changeset pattern: ".*\\.h", comparator: "REGEXP"
                    changeset pattern: ".*\\.hpp", comparator: "REGEXP"
                    changeset pattern: ".*\\.cxx", comparator: "REGEXP"
                    changeset pattern: "README.md", comparator: "REGEXP"
                }
            }
            steps {
                sh '(git diff-tree --no-commit-id --name-only -r $(git symbolic-ref --short HEAD)) && doxygen'
            }
        }
        stage("Tests"){
            steps {
                sh './tests/tests'
            }
        }
        stage("Git add commit push"){
            when {
                anyOf {
                    changeset pattern: ".*\\.cpp", comparator: "REGEXP"
                    changeset pattern: ".*\\.h", comparator: "REGEXP"
                    changeset pattern: ".*\\.hpp", comparator: "REGEXP"
                    changeset pattern: ".*\\.cxx", comparator: "REGEXP"
                    changeset pattern: "README.md", comparator: "REGEXP"
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
}
