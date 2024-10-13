
    
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        # Store the original number
        original = x
        reversed_num = 0
        
        # Reverse the digits of the number
        while x > 0:
            digit = x % 10
            reversed_num = reversed_num * 10 + digit
            x //= 10
        
        # Check if the original number is equal to the reversed number
        return original == reversed_num
