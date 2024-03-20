import json
import sys

def listDone():
    with open('problems.json', 'r') as file:
        data = json.load(file)

    done = data['done']

    print("done problems:")
    for p in done:
        print(p)

def listUndone():
    with open('problems.json', 'r') as file:
        data = json.load(file)

    undone = data['undone']
   
    print("undone problems:")
    for p in undone:
        print(p)


def listAll():
    with open('problems.json', 'r') as file:
        data = json.load(file)

    undone = data['undone']
    done = data['done']

    print("done problems:")
    for p in done:
        print(p)
    print("undone problems:")
    for p in undone:
        print(p)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 listproblems.py <option>")
        sys.exit(1)

    mode = sys.argv[1]
    if mode == "done":
        listDone()
    elif mode == "undone":
        listUndone()
    elif mode == "all":
        listAll()
    else:
        print("Unkown option", mode)
        print("Options: \n--done -d\n--undone -u\n--all -a\n")



    