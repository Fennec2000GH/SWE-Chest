
# https://elixir-lang.org/getting-started/pattern-matching.html

# Match operator
x = 1
1 = x

# Common errors from pattern matching
try do
    2 = x
rescue
    MatchError -> IO.puts "Match error detected."
end

try do
    raise CompileError
rescue
    CompileError -> IO.puts "Compile error detected."
end

{a, b, c, d} = {1, 2, 3, 4}
IO.puts "#{a}, #{b}, #{c}, #{d}"

[a, b, _] = ["first", "second", "third"]
IO.puts "#{a}, #{b}"

[head | tail] = [1, 2, 4, 8]
IO.inspect head
IO.inspect tail


# Pin operator
^x = 1
try do
    [^a, b, c] = ["one", "two", "three"]
rescue
    MatchError -> IO.puts "Pinned variable causes MatchError."
end
