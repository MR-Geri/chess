pipeline{
    agent any
    options {
        timestamps()
    }
    stages {
        stage("CMAKE compile"){
            steps {
                sh 'cmake /var/jenkins_home/workspace/chess_dev'
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
