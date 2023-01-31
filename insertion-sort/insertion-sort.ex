defmodule InsertionSort do
    defp generate_array(size) do
        Enum.reduce(1..size, [], fn i, acc ->
            index = Enum.random(0..i)
            List.insert_at(acc, index, i)
        end)
    end

    defp insertion_sort(arr) do
        Enum.reduce(arr, [], fn key, acc ->
            index = Enum.reduce(acc, 0, fn x, inner_acc ->
                if x < key do
                    inner_acc + 1
                else
                    inner_acc
                end
            end)
            List.insert_at(acc, index, key)
        end)
    end

    defp compare_lists(subject, expected) do
        n_diff = Enum.reduce(0..length(expected) - 1, 0, fn i, acc ->
            if Enum.at(subject, i) == Enum.at(expected, i) do
                acc
            else
                acc + 1
            end
        end)
        n_diff == 0
    end

    def main() do
        size = 30_000

        # Generate array
        {gen_time, arr} = :timer.tc(fn -> generate_array(size) end)

        # Sort array
        {sort_time, res} = :timer.tc(fn -> insertion_sort(arr) end)

        # Eval sorted array with expected result
        expected = Enum.to_list(1..size)
        are_equal = compare_lists(res, expected)

        # Output results
        IO.puts "1. Time to generate list: #{gen_time / 1_000} ms"
        if not are_equal do
            IO.puts "2. The result list is NOT sorted as expected"
        else
            IO.puts "2. The result list is sorted as expected"
            IO.puts "3. Time to sort the list #{sort_time / 1_000} ms"
        end
    end
end

InsertionSort.main()
