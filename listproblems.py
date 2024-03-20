import json
import sys

def printDone(data):
    done = data['done']
    print("DONE problems:")
    for p in done:
        print("url:", p['url'])
        try:
            if len(p['categories']) > 0:
                print('CATEGORIES:')
                for cat in p['categories']:
                    print('  ', cat)
        except:
            print()
            continue
        finally:
            print()

def printUndone(data):
    undone = data['undone']
    print("UNDONE problems:")
    for p in undone:
        print("url:", p['url'])
        try:
            if len(p['categories']) > 0:
                print('CATEGORIES:')
                for cat in p['categories']:
                    print('  ', cat)
        except:
            print('\n')
            continue
        finally:
            print()

def listDone():
    with open('problems.json', 'r') as file:
        data = json.load(file)

    printDone(data)

   

def listUndone():
    with open('problems.json', 'r') as file:
        data = json.load(file)

    printUndone(data)


def listAll():
    with open('problems.json', 'r') as file:
        data = json.load(file)

    printDone(data)
    printUndone(data)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        listUndone()
        sys.exit(1)

    mode = sys.argv[1]
    if mode == "--done" or mode == "-d":
        listDone()
    elif mode == "--undone" or mode == "-u":
        listUndone()
    elif mode == "--all" or mode == "-a":
        listAll()
    else:
        print("Unkown option", mode)
        print("Options: \n--done -d\n--undone -u\n--all -a\n")



    