pipeline {
    agent any

    stages {
        stage ("Print Hello World") {
            steps {
                echo "Hello Jenkins World"
            }
        }

        stage ("Do you run clang-format ?") {
            agent {
                docker {
                    image "47.90.255.243:6789/daisy/binary-builder"
                    registryUrl "http://47.90.255.243:6789"
                    registryCredentialsId 'private-docker'
                    reuseNode true
                }
            }
            steps {
                sh "find ${WORKSPACE}/ \\( -name \"*.cpp\" -or -name \"*.h\" \\) ! -path \"./third_party/*\" | clang-format -style=file -output-replacements-xml | grep -c \"<replacement \" > /dev/null"
            }
            post {
                success {
                    echo "clang-format checking passed."     
                }
                failure {
                    sh "find ${WORKSPACE}/ \\( -name \"*.cpp\" -or -name \"*.h\" \\) ! -path \"./third_party/*\" | clang-format -style=file > clang-format.log"
                    archive "clang-format.log"
                }
            }
        } 

        stage ("Pipeline was Interrupt") {
            steps {
                echo "Pipeline was Interrupt"
            }
        }
    }
}
