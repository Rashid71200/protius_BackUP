from PIL import Image

# Load the JPG image
image = Image.open("img.jpg")
# Convert the image to RGB mode (if not already)
if image.mode != 'RGB':
    image = image.convert('RGB')

# Get the width and height of the image
width, height = image.size

# Define the maximum size
max_size = 11264

# Initialize an empty list to store uint16_t values
uint16_t_array = []

# Iterate through each pixel and convert to uint16_t
for y in range(height):
    for x in range(width):
        # Get RGB values
        r, g, b = image.getpixel((x, y))
        
        # Convert RGB to uint16_t
        uint16_value = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3)
        
        # Check if the array size has reached the maximum
        if len(uint16_t_array) >= max_size:
            break
        
        # Append to the list
        uint16_t_array.append(uint16_value)

    # Check if the array size has reached the maximum
    if len(uint16_t_array) >= max_size:
        break

# Determine the size of the uint16_t_array
array_size = len(uint16_t_array)

# Print the size of the array
print("Array size:", array_size)

# Define the output file path
output_file_path = "output.txt"

# Write the generated C array to the TXT file
with open(output_file_path, "w") as txt_file:
    txt_file.write("const PROGMEM uint16_t dragonBitmap[{}] = {{\n".format(array_size))
    for value in uint16_t_array:
        txt_file.write("    0x{:04X},\n".format(value))
    txt_file.write("};")

print("C array saved to", output_file_path)