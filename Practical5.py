def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def display_top_scores(arr, top_n=5):
    print("Top {} scores:".format(top_n))
    for score in arr[-top_n:]:
        print(f"{score:.2f}")

def main():
    # Example percentages of students
    percentages = [85.5, 92.3, 76.4, 88.0, 67.5, 95.1, 84.2, 73.8, 91.0, 78.6]

    # Sort using Selection Sort
    sorted_percentages_selection = percentages[:]
    selection_sort(sorted_percentages_selection)
    display_top_scores(sorted_percentages_selection)

    # Sort using Bubble Sort
    sorted_percentages_bubble = percentages[:]
    bubble_sort(sorted_percentages_bubble)
    display_top_scores(sorted_percentages_bubble)

if __name__ == "__main__":
    main()
