
# https://elixir-lang.org/getting-started/keywords-and-maps.html

# Keywword lists
kw = [{:a, 0}, {:b, 1}, {:c, 2}, {:d, 3}]
IO.write "kw = "; IO.inspect kw
IO.write "kw ++ [e: 4] = "; IO.inspect kw ++ [e: 4]
IO.write "kw -- [b: 1] = "; IO.inspect kw -- [b: 1]
IO.write "[a: 39] ++ kw = "; IO.inspect [a: 39] ++ kw
IO.puts "kw[:a] = #{kw[:a]}"
IO.puts "kw[:c] = #{kw[:c]}"
IO.puts "kw == [a: 0, b: 1, c: 2, d: 3]? #{kw == [a: 0, b: 1, c: 2, d: 3]}"

# Maps
map = %{:apple => "fruit", :banana => "fruit", "broccoli" => 'green', 39 => "number"}
IO.write "map = "; IO.inspect map
IO.puts "map[:apple] = #{map[:apple]}"
IO.puts "map[39] = #{map[39]}"
map = %{map | "broccoli" => nil, 39 => "thirty-nine"}
IO.puts "new map[\"broccoli\"] = #{map["broccoli"]}"
IO.puts "new map[39] = #{map[39]}"
atom_map = %{a: 0, b: 1, c: "cat"}
IO.write "atom_map = "; IO.inspect atom_map
IO.puts "atom_map.a = #{atom_map.a}, atom_map.b = #{atom_map.b}, atom_map.c = #{atom_map.c}"

# Nested data structures
users = [
  john: %{name: "John", age: 27, languages: ["Erlang", "Ruby", "Elixir"]},
  mary: %{name: "Mary", age: 29, languages: ["Elixir", "F#", "Clojure"]}
]
IO.write "users = "; IO.inspect users
IO.write "users[:john][:languages] = "; IO.inspect users[:john][:languages]
