pipeline{
    agent any
    options {
        timestamps()
    }
    stages {
        stage("CMAKE compile"){
            steps {
                sh 'pwd'
                sh 'ls'
                sh 'ls /var/jenkins_home/tools/hudson.plugins.cmake.CmakeTool/3.24.3/bin/'
                cmake installation: 'InSearchPath'
                sh 'pwd'
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
