pipeline{
    agent any
    options {
        timestamps()
    }
    stages {
        stage("One"){
            steps {
                sh "sleep 1"
            }
        }
        stage("Two"){
            steps {
                sh "sleep 5"
            }
        }
        stage("Three"){
            steps {
                sh "sleep 1"
            }
        }
    }
}
