import shutil
import os

for root, dirs, files in os.walk('.'):
  for dir in dirs:
    print(f'{root}/{dir}')
    shutil.rmtree(f'{root}/{dir}')
  # for file in files:
    # shutil.move(f'{root}/{file}', f'{root}{file}')
