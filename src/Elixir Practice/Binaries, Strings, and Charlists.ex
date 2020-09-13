
# https://elixir-lang.org/getting-started/binaries-strings-and-char-lists.html

# Unicode and code points
IO.puts "Unicode for a: #{?a}"
IO.puts "Unicode for 1: #{?1}"
IO.puts "Unicode for #: #{?#}"
IO.puts "Emoji: 🌩️"
IO.puts "\\u4e03 === 七: #{"\u4e03" === "七"}"
IO.puts "\\u0434 === д: #{"\u0434" === "д"}"

# UTF-8 encoding
string = "hełło"
IO.puts string
IO.puts "length: #{String.length(string)}"
IO.puts "byte size: #{byte_size(string)}"
IO.puts string <> <<0>>
IO.inspect(string, binaries: :as_binaries)

# Bitstrings
IO.write "Bitstring of 4: "; IO.inspect <<4>>
IO.write "Bitstring of 18 (size 16): "; IO.inspect <<18::16>>
IO.write "Bitstring wrap around: "; IO.inspect <<257>>
 
# Binaries
IO.puts "Is 0011 (<<3::4>>) a bit string? #{is_bitstring(<<3::4>>)}"
IO.puts "Is 0011 (<<3::4>>) a binary? #{is_binary(<<3::4>>)}"
IO.puts "Is <<00001111, 11110000, 00000001>> (<<15, 240, 1>>) a bit string? #{is_bitstring(<<15, 240, 1>>)}"
IO.puts "Is <<00001111, 11110000, 00000001>> (<<15, 240, 1>>) a binary? #{is_binary(<<15, 240, 1>>)}"
IO.puts "Is 0000000100000100 (<<36::16>>) a binary? #{is_binary<<36::16>>}"

<<x, y, z>> = <<2, 4, 6>>
IO.puts "x = #{x}, y = #{y}, z = #{z}"
<<0, 1, x::binary>>  = <<0, 1, 2, 3, 4, 5, 6>>
IO.write "x = "; IO.inspect x
<<head::binary-size(4), tail::binary>> = <<0, 1, 2, 3, 4, 5, 6>>
IO.write "head = "; IO.inspect head; IO.write "tail = "; IO.inspect tail
IO.puts "Is <<255, 255, 255>> a valid string? #{String.valid?(<<255, 255, 255>>)}"
IO.write "<<0, 1, 2>> <> <<3, 4, 5, 6>> = "; IO.inspect <<0, 1, 2>> <> <<3, 4, 5, 6>>
<<x, rest::binary>> = "übermensch"
IO.write "x = "; IO.inspect <<x::utf8>>; IO.write "rest = "; IO.inspect rest
<<x::utf8, rest::binary>> = "übermensch"
IO.write "x (with UTF-8) = "; IO.inspect <<x::utf8>>; IO.write "rest = "; IO.inspect rest

# Charlists
c = 'underwater'
IO.write "charlist c = "; IO.inspect c
IO.puts "Is c a list? #{is_list(c)}"
IO.puts "First character in c: #{List.first(c)}"
IO.inspect(c, charlists: :as_lists)

w = "world"
IO.write "\"world\" as a charlist: "; IO.inspect to_charlist(w)
IO.write "[97, 98, 99, 100] as string: "; IO.inspect to_string([97, 98, 99, 100])
IO.write ":item as string: "; IO.inspect to_string(:item)
IO.write "18 as string: "; IO.inspect to_string(18)

IO.write "\'12345\' ++ \'67890\' = "; IO.inspect '12345' ++ '67890'
IO.write "\'12345\' -- \'45\' = "; IO.inspect '12345' -- '45'
IO.puts "\"hello \" <> \"world\" = #{"hello " <> "world"}"
