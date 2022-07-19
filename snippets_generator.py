import os,json 

class Snippet():
    def __init__(self,name,prefix,body,description=""):
        self.name = name 
        self.prefix = prefix 
        self.body = body 
        self.description = description
    
    def to_json(self):
        json_body = json.dumps({
            "prefix": self.prefix,
            "body": self.body,
            "description": self.description
        })
        return f'"{self.name}": ' + json_body

def to_path(include_sentence):
    return include_sentence.removeprefix("#include").replace('"','').strip()

REMOVE_SENTENCE = [
    "#pragma once\n",
    "#include <bits/stdc++.h>\n",
    "using namespace std;\n",
]

# TODO: open file ecursively and create snippet
def readfile_recursively(path):
    body = []
    with open(path,mode = "r") as f:
        for line in f:
            if line in REMOVE_SENTENCE:
                continue
            body.append(line.rstrip())
    return body

def create_snippets(path,prefix,description=""):
    snippet_body = readfile_recursively(path)
    return Snippet(
        name = path,
        prefix = prefix,
        body = snippet_body,
        description = description
    )

def output_snippets(snippets):
    with open(".vscode/procon.code-snippets",mode = "w") as f:
        f.write("{")
        for snippet in snippets:
            f.write(snippet.to_json())
            f.write(",")
        f.write("}")

REMOVE_DIR = [
    ".git",
    ".github",
    ".verify-helper",
    ".vscode",
    "ac-library",
    "template",
    "test",
    "venv",
]

def main():
    snippets = []

    cwd_path = "./"
    for dir in os.listdir(cwd_path):
        dir_path = os.path.join(cwd_path,dir) 
        if ( not os.path.isdir(dir_path) ) or ( dir in REMOVE_DIR ):
            continue
        for file in os.listdir(dir_path):
            file_path = os.path.join(dir_path,file)
            prefix = file.rstrip(".cpp")
            snippets.append(create_snippets(file_path,f"snp {prefix}"))

    output_snippets(snippets)

if __name__ == "__main__":
    main()