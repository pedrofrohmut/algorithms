defmodule InsertionSort do
    defp func(), do: fn -> main() end

    defp time_it(function) do
        # :timer.tc returns the time in microseconds
        function |> :timer.tc() |> elem(0)
    end

    defp print_list(arr), do: arr |> Kernel.inspect() |> IO.puts()

    def time() do
        time = time_it(func())
        "Time: #{time} microseconds #{time / 1_000} millisencond #{time / 1_000_000} seconds"
    end

    def main() do
        arr = [41, 5, 30, 34, 19, 20, 31, 33, 2, 15, 32, 25, 17, 38, 4, 6, 23, 29, 40, 14, 7, 36, 21, 1, 16, 39, 26, 35, 9, 12, 13, 24, 3, 37, 18, 27, 10, 8, 28, 11, 22]

        result_array = Enum.reduce(arr, [], fn elem, res ->
            left = Enum.take_while(res, fn x -> x < elem end)
            right = res -- left
            left ++ [elem] ++ right
        end)

        # print_list(result_array)

        result_array
    end
end

InsertionSort.main()
