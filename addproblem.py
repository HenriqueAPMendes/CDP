import json
import sys

def addProblem(url, categories):
    with open('problems.json', 'r') as file:
        data = json.load(file)

    undone = data['undone']
    problem = {}
    problem['url'] = url
    if len(categories) > 0:
        problem['categories'] = []
        for cat in categories:
            problem['categories'].append(cat)

    for obj in undone:
        if obj['url'] == url:    
            print(f"Problem '{url}' already listed.")
            return
    else:
        undone.append(problem)

    with open('problems.json', 'w') as file:
        json.dump(data, file, indent=2)

    print(f"Marked problem '{url}' as 'undone'.")
    

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 addproblem.py <url> [categories...]")
        sys.exit(1)

    url = sys.argv[1]
    categories = sys.argv[2:]
    addProblem(url, categories)
