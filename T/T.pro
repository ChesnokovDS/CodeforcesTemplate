TEMPLATE = app
CONFIG += console c++11 c++14
CONFIG -= app_bundle
CONFIG -= qt


comparison_test = 1
validation_test = 2
DEFINES += "DO_TEST_BY_COMPARISON=$$comparison_test"
DEFINES += "DO_TEST_BY_ASSERT=$$validation_test"
DEFINES += "TEST_TYPE=$$comparison_test"


DEFINES += "INPUT_FILE=\\\"input.txt\\\""
DEFINES += "ITERATIONS=100"
generate_random = 1
input_from_file = 2
DEFINES += "GENERATE_RANDOM_INPUT=$$generate_random"
DEFINES += "LOAD_INPUT_FROM_FILE=$$input_from_file"
DEFINES += "INPUT_SOURCE=$$input_from_file"


DEFINES += "ANSWER_FILE=\\\"answers.txt\\\""
load_answer = 1
calc_answer = 2
DEFINES += "LOAD_ANSWER_FROM_FILE=$$load_answer"
DEFINES += "MAKE_ANSWER_BY_ALTERNATIVE_SOLUTION=$$calc_answer"
DEFINES += "ORACUL_TYPE=$$load_answer"


DEFINES += "DO_TESTS"

#DEFINES += "OUTPUT_TO_FILE=\\\"output.txt\\\""

SOURCES += \
    T.cpp
