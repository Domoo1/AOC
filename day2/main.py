# Open the file
safe = 0
def check(nums):
    inc = nums[0] < nums[1];
    if inc:
        for i in range(len(nums) - 1):
            if(nums[i] >= nums[i + 1] or (nums[i + 1] - nums[i]) > 3):
                return 0
    else:    
        for i in range(len(nums) - 1):
            if(nums[i] <= nums[i + 1] or (nums[i] - nums[i + 1]) > 3):
                return 0
            
    return 1

    

with open("numbers", "r") as file:
    lines = file.readlines()
    data = []
    for line in lines:
        # Strip any trailing newline or whitespace
        line = line.strip()

        # Split the line into a list of string tokens
        tokens = line.split()

        # Convert each token to an integer manually
        numbers = []
        for token in tokens:
            numbers.append(int(token))  # Convert string to integer

        data.append(numbers)
        # Add the numbers list to the parsed data
        

# Print the parsed data
for line in data:
    if(check(line)):
        safe += 1
print(safe)



    