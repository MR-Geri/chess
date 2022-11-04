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
        stage("Tests"){
            steps {
                sh './tests/tests'
            }
        }
    }
}
