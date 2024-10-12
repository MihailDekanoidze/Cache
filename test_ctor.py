from random import*

test_number = 10


for i in range(test_number):
    test_file = open("tests/mytest" + str(i), 'w')

    buffer_len = randint(0, 100)
    question_number = randint(0, 100000)
    test_file.write(str(buffer_len) +  " " + str(question_number))

    for j in range(question_number):
        test_file.write(" " +  str(randint(0 ,100000)))

    test_file.close() 
