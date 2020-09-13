
# https://elixir-lang.org/getting-started/basic-operators.html

# Manipulate lists

li = [1, 2, 3]
IO.puts "li: #{li}"
li = li ++ [4, 5, 6]
IO.puts "li: #{li}"
li = li -- [2]
IO.puts "li: #{li}"
IO.inspect li

# Manipulate strings
s = "some"
IO.puts "s: #{s}"
s = s <> " text" <> " has" <> " been" <> " appended"
IO.puts "s: #{s}"

# Boolean operators
IO.puts "true and true: #{true and true}"
IO.puts "true and false: #{true and false}"
IO.puts "true or false: #{true or false}"
IO.puts "not false: #{not false}"

# False circuit examples
false and raise("This error will never be raised.")
true or raise("This error will never be raised.")

# Lazy boolean oeprators
IO.puts ":atom && true: #{:atom && false}"
IO.puts "16 || false: #{16 || false}"

# Compare with data type in consideration
IO.puts "1 == 1.0: #{1 == 1.0}"
IO.puts "1 === 1.0: #{1 === 1.0}"
IO.puts "false == nil: #{false == nil}"
IO.puts "false === nil: #{false === nil}"

# Comparing different data types
IO.puts "1 < :atom: #{1 < :atom}"
