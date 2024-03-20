import json
import random
import sys

def getRandomProblem():
    with open('problems.json', 'r') as file:
        data = json.load(file)

    undone = data['undone']
    index = random.randint(0, len(undone)-1)
    print("url:", undone[index]['url'])
    try:
        if len(undone[index]['categories']) > 0:
            print('CATEGORIES:')
            for cat in undone[0]['categories']:
                print(cat)
    except:
        sys.exit(0)

def getFirstProblem():
    with open('problems.json', 'r') as file:
        data = json.load(file)

    undone = data['undone']
    print("url:", undone[0]['url'])
    try:
        if len(undone[0]['categories']) > 0:
            print('CATEGORIES:')
            for cat in undone[0]['categories']:
                print(cat)
    except:
        sys.exit(0)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        getFirstProblem()
    elif sys.argv[1] == "--random" or sys.argv[1] == "-r":
        getRandomProblem()
