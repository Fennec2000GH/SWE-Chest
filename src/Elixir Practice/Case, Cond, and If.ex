
# https://elixir-lang.org/getting-started/case-cond-and-if.html

# Cases
x = {1, 2, 3}
case x do
    {4, 5, 6} -> IO.puts "first case"
    {7, 8, 9} -> IO.puts "second case"
    {1, 2, 3} -> IO.puts "third case"
    _ -> IO.puts "default case"
end

case x do
    {a, b, c} when a >= 0 and b >= 0 and c >= 0 -> IO.puts "All non-negatives."
    {_, _, c} when c < 0 -> IO.puts "Third element is negative."
    _ -> IO.puts "default case"
end

try do
    case x do
        1 -> IO.puts "1"
        [1, 2, 3] -> IO.puts "[1, 2, 3]"
        nil -> IO.puts nil
    end
rescue
    CaseClauseError -> IO.puts "No case matches."
end

# Cond
cond do
    1 + 1 == 3 -> IO.puts "1 + 1 == 3"
    4 / 5 >= 1 -> IO.puts "4 / 5 >= 1"
    String.first("cat") == "c" -> IO.puts "c"
    true -> IO.puts "default value"
end

cond do
    false || -4 -> IO.puts "truthy value"
end

# If and Unless statements
x = 1
if x == 1 do
    IO.puts "x == 1"
else
    IO.puts "else block"
end

unless x < 10 do
    IO.puts "x has at least 2 digits."
else
    IO.puts "x may be negative, have only a single digit, or both."
end
