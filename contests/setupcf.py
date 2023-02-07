#!/bin/python3
import requests
import os
from shutil import copyfile
from bs4 import BeautifulSoup
from sys import argv

# pip3 install BeautifulSoup lxml
# python3 setupcf.py {contest id}

def get_problems(contest):
    req = requests.get(f"https://codeforces.com/contest/{contest}")
    soup = BeautifulSoup(req.text, "lxml")
    table = soup.find('table', class_='problems')
    problems = [row.find('a')['href'] for row in table.findAll('tr')[1:]]

    for problem in problems:
        print(f"getting problem {problem}")
        letter = problem.split('/')[-1]
        os.mkdir(f'{contest}/{letter}')
        copyfile('../template.cc', f'{contest}/{letter}/{letter}.cc')

        req = requests.get(f"https://codeforces.com/{problem}")
        soup = BeautifulSoup(req.text, "lxml")
        samples = soup.findAll(class_='input')
        samples = [i.find('pre').text for i in samples]

        for i, sample in enumerate(samples):
            with open(f"{contest}/{letter}/{i+1}{letter}.in", "w") as f:
                f.write(sample)

if __name__ == "__main__":
    contest = argv[1]
    print(f"setting up codeforces {contest}")
    os.mkdir(contest)
    get_problems(contest)
