#Created by Owais Bangash, SIAT CAS China. 

from PIL import Image
import os

# Define the target dimensions
target_width = 716
target_height = 689

# Specify the directory paths
source_directory = 'C:/Users/admin/Downloads/OpenCv projects/Experiment'
target_directory = 'C:/Users/admin/Downloads/OpenCv projects/Experiment/New'

# Create the target directory if it doesn't exist
os.makedirs(target_directory, exist_ok=True)

# Iterate through the files in the source directory
for filename in os.listdir(source_directory):
    if filename.endswith('.png'):
        try:
            # Open the image
            image_path = os.path.join(source_directory, filename)
            image = Image.open(image_path)

            # Resize the image
            resized_image = image.resize((target_width, target_height))

            # Generate the target file path
            target_path = os.path.join(target_directory, filename)

            # Save the resized image to the target directory
            resized_image.save(target_path)

            # Close the image
            image.close()
        except Exception as e:
            print(f"An error occurred while processing {filename}: {e}")

print("Image resizing and saving complete!")
