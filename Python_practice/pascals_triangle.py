from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = []

        for i in range(numRows):
            row = [1]
            if triangle:
                last_row = triangle[-1]
                for j in range(1, i):
                    row.append(last_row[j - 1] + last_row[j])
                row.append(1)
            triangle.append(row)

        return triangle

def printTriangle(triangle: List[List[int]]):
    for row in triangle:
        print(row)

def main():
    numRows = int(input("Enter number of rows: "))
    sol = Solution()
    result = sol.generate(numRows)
    print("Pascal's Triangle:")
    printTriangle(result)

if __name__ == "__main__":
    main()
