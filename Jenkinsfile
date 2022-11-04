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
            steps {
                sh '(git diff-tree --no-commit-id --name-only -r $(git symbolic-ref --short HEAD)) | grep \'.*[\\.cpp|\\.h|\\.hpp|\\.cxx]\' | xargs -n 1 clang-format --sort-includes --style=LLVM -i || true'
            }
        }
        stage("Create documentation"){
            steps {
                sh '(git diff-tree --no-commit-id --name-only -r $(git symbolic-ref --short HEAD)) | grep \'.*[\\.cpp|\\.h|\\.hpp|\\.cxx]\' && doxygen || true'
            }
        }
        stage("Tests"){
            steps {
                sh './tests/tests'
            }
        }
        stage("Git add commit push"){
            steps {
                sh 'git diff-files --name-only && xargs -n 1 git add'
                sh 'git commit -m \"$(git show-branch --no-name $(git symbolic-ref --short HEAD)) +edit_jenkins\" --amend --author="Jenkins <jenkins@mr_geri.ru>"'
                sh 'git push'
            }
        }
    }
}
