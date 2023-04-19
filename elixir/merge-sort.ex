defmodule MergeSort do
    defp generate_array(size) do
        Enum.reduce(1..size, [], fn i, acc ->
            rand_index = Enum.random(0..i)
            List.insert_at(acc, rand_index, i)
        end)
    end

    defp get_left_and_right(arr) do
        extra = if(Integer.mod(length(arr), 2) == 0, do: 0, else: 1)
        half_size = floor(length(arr) / 2)
        left = Enum.slice(arr, 0..(half_size + extra - 1))
        right = Enum.slice(arr, (half_size + extra)..length(arr) - 1)
        [left, right]
    end

    defp get_index([], _key, index), do: index

    defp get_index(list, key, index) do
        [head | body] = list
        if head >= key do
            index
        else
            get_index(body, key, index + 1)
        end
    end

    defp insertion_sort(arr) do
        Enum.reduce(arr, [], fn key, acc ->
            index = get_index(acc, key, 0)
            List.insert_at(acc, index, key)
        end)
    end

    defp merge_sort(left, []), do: left

    defp merge_sort([], right), do: right

    defp merge_sort(left, right) do
        [left_head | left_tail] = left
        [right_head | right_tail] = right
        if left_head < right_head do
            [left_head | merge_sort(left_tail, right)]
        else
            [right_head | merge_sort(left, right_tail)]
        end
    end

    defp compare_arrays([], []), do: true

    defp compare_arrays(_subject, []), do: false

    defp compare_arrays([], _expected), do: false

    defp compare_arrays(subject, expected) do
        [subject_head | subject_tail] = subject
        [expected_head | expected_tail] = expected
        if subject_head != expected_head do
            false
        else
            compare_arrays(subject_tail, expected_tail)
        end
    end

    def main() do
        size = 30_000

        # Generate array
        {gen_time, arr} = :timer.tc(fn -> generate_array(size) end)
        # arr |> Kernel.inspect() |> IO.puts()

        {sort_time, sorted} = :timer.tc(fn ->
            # Get left and right. The halves of the array
            [left, right] = get_left_and_right(arr)

            # Sort left and right (insertion sort)
            sorted_left = insertion_sort(left)
            sorted_right = insertion_sort(right)

            # Merge sorted_left and sorted_right
            merge_sort(sorted_left, sorted_right)
        end)

        # Eval sorted array
        expected = Enum.to_list(1..size)
        are_equal = compare_arrays(sorted, expected)

        # Output the results
        IO.puts "1. Time to generate array: #{gen_time / 1_000} ms"
        if not are_equal do
            IO.puts "2. Result array is NOT sorted as expected"
        else
            IO.puts "2. Result array is sorted as expected"
            IO.puts "3. Time to merge sort the array: #{sort_time / 1_000} ms"
        end
    end
end

MergeSort.main()
