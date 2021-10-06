pipeline {
    agent any

    stages {
        stage ("Print Hello World") {
            echo "Hello Jenkins World"
        }

        stage ("Do you run clang-format ?") {
            sh "find ${WORKSPACE}/ \\( -name \"*.cpp\" -or -name \"*.h\" \\) ! -path \"./third_party/*\" | clang-format -style=file -output-replacements-xml | grep -c \"<replacement \" > /dev/null"
        }
    }
}
