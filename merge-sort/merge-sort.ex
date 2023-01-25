defmodule MergeSort do
    defp get_left_and_right(arr) do
        size = floor(length(arr) / 2)
        left = Enum.slice(arr, 0..(size - 1))
        right = Enum.slice(arr, size..length(arr) - 1)
        [left, right]
    end

    defp order_array(arr) do
        Enum.reduce(arr, [], fn curr, acc ->
            left = Enum.take_while(acc, fn x -> x < curr end)
            right = acc -- left
            left ++ [curr] ++ right
        end)
    end

    defp merge_sort(left, []), do: left

    defp merge_sort([], right), do: right

    defp merge_sort(left, right) do
        [left_head | left_tail] = left
        [right_head | right_tail] = right
        if left_head < right_head do
            [left_head] ++ merge_sort(left_tail, right)
        else
            [right_head] ++ merge_sort(left, right_tail)
        end
    end

    defp print_array(arr) do
        for {elem, i} <- Enum.with_index(arr), do: IO.puts "[#{i}]: #{elem}"
    end

    def time_it() do
        time = fn -> main() end
        |> :timer.tc()
        |> elem(0)
        |> Kernel./(1_000)
        "Total: #{time} in milliseconds"
    end

    def main() do
        arr = [41, 5, 30, 34, 19, 20, 31, 33, 2, 15, 32, 25, 17, 38, 4, 6, 23, 29, 40, 14, 7, 36, 21, 1, 16, 39, 26, 35, 9, 12, 13, 24, 3, 37, 18, 27, 10, 8, 28, 11, 22]

        [left, right] = get_left_and_right(arr)

        left = order_array(left)
        right = order_array(right)

        result_array = merge_sort(left, right)

        # print_array(result_array)

        result_array
    end
end

# MergeSort.main()
