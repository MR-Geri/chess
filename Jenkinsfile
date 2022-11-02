pipeline{
    agent any
    options {
        timestamps()
    }
    stages {
        stage("CMAKE compile"){
            steps {
                cmake arguments: '-DCMAKE_TOOLCHAIN_FILE=CMakeLists.txt', installation: 'InSearchPath'
                cmakeBuild buildType: 'Release', cleanBuild: true, installation: 'InSearchPath', steps: [[withCmake: true]]
            }
        }
        stage("MAKE compile"){
            steps {
                sh 'make'
            }
        }
        stage("Tests"){
            steps {
                sh '''
                    if [[ ! -z $(./tests/tests | grep -m 1 'FAIL!') ]]; then
                        exit 1
                    fi
                    exit 0
                '''
            }
        }
    }
}
