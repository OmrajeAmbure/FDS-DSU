def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

def display_top_scores(arr, top_n=5):
    print("Top {} scores:".format(top_n))
    for score in arr[-top_n:]:
        print(f"{score:.2f}")

def main():
    # Example percentages of students
    percentages = [88.5, 74.3, 91.2, 85.7, 66.5, 94.8, 79.0, 82.4, 89.1, 73.6]

    # Sort using Insertion Sort
    sorted_percentages_insertion = percentages[:]
    insertion_sort(sorted_percentages_insertion)
    display_top_scores(sorted_percentages_insertion)

    # Sort using Shell Sort
    sorted_percentages_shell = percentages[:]
    shell_sort(sorted_percentages_shell)
    display_top_scores(sorted_percentages_shell)

if __name__ == "__main__":
    main()

