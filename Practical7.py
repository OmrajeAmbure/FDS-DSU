def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)

def display_top_scores(arr, top_n=5):
    print("Top {} scores:".format(top_n))
    for score in arr[-top_n:]:
        print(f"{score:.2f}")

def main():
    # Input the number of students
    n = int(input("Enter the number of students: "))
    percentages = []

    # Input percentages from user
    for i in range(n):
        score = float(input(f"Enter percentage for student {i + 1}: "))
        percentages.append(score)

    # Sort using Quick Sort
    sorted_percentages = quick_sort(percentages)
    display_top_scores(sorted_percentages)

if __name__ == "__main__":
    main()
