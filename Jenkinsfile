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
                changeset pattern: ".*[\\.cpp|\\.h|\\.hpp|\\.cxx]", comparator: "REGEXP"
            }
            steps {
                sh '(git diff-tree --no-commit-id --name-only -r $(git symbolic-ref --short HEAD)) | xargs -n 1 clang-format --sort-includes --style=LLVM -i'
            }
        }
        stage("Create documentation"){
            when {
                changeset pattern: ".*[\\.cpp|\\.h|\\.hpp|\\.cxx]", comparator: "REGEXP"
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
                changeset pattern: "docs/.*|.*[\\.cpp|\\.h|\\.hpp|\\.cxx]", comparator: "REGEXP"
            }
            steps {
                sh 'git add .'
                sh 'git config --global user.email "ilya.kamckine@yandex.ru"'
                sh 'git config --global user.name "Jenkins"'
                sh 'git commit -m \"$(git show-branch --no-name $(git symbolic-ref --short HEAD)) +edit_jenkins\"'
                sh 'git push --set-upstream origin $(git symbolic-ref --short HEAD)'
            }
        }
    }
}
