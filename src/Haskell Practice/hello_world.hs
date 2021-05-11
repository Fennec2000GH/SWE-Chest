
main::IO()
main = do
    -- Println
    putStrLn "Hello World!"

    -- Numbers
    print (2 + 2)
    print (6 + (4 * 6) + 6)
    print (3.6 * 1.2)

    -- Characters
    print 'r'
    print '\114'

    -- Strings
    print "skyscraper"

    -- Booleans
    print (True && True)
    print (True && False)
    print (True || False)
    print (False || False)

    -- List / List comprehension
    print [0, 0.123, 1.24, 111.999]
    print [1..10]
    print [1 | x <- [5..10]]
    print [x*4 | x <- [1..5]]
    print [x^2 | x <- [1..10]]

    -- Tuple
    print (1, 2.0, 'r', "Autumn")
