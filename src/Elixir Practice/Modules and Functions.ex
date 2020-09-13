
# https://elixir-lang.org/getting-started/modules-and-functions.html

defmodule Math do
    def sum(a, b) do
        a + b
    end

    def sub(a, b) do
        a - b
    end

    def mul(a, b) do
        a * b
    end

    def divide(a, b) when b != 0 do
        a / b
    end

    def num_primes(a) when a >=2 do
        Enum.count(2..a, &is_prime(&1))
    end

    def is_prime(a) when is_integer(a) and a >= 2 do
        if a <= 3 do true end
        sqrt_a = trunc(Float.floor(:math.sqrt(a)))
        not Enum.any?(2..sqrt_a, &is_factor(&1, a))
    end

    defp is_factor(a, b) do
        rem(b, a) == 0
    end

end

IO.puts "Math.sum(1, 2) = #{Math.sum(1, 2)}"
IO.puts "Math.sub(2, 1) = #{Math.sub(2, 1)}"
IO.puts "Math.mul(4, 6)  =#{Math.mul(4, 6)}"
IO.puts "Math.divide(6, 3) = #{Math.divide(6, 3)}"
IO.puts "Math.is_prime(7) = #{Math.is_prime(7)}"
IO.puts "Math.num_primes(1000) = #{Math.num_primes(1000)}"
