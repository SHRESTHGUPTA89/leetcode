class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Negative numbers are not palindromes
        if x < 0:
            return False
        
        # Convert the number to a string
        s = str(x)
        
        # Check if the string reads the same backward and forward
        return s == s[::-1]
