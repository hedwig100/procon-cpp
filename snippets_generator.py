import os,json,pathlib

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

IGNORE_SENTENCE = [
    "#pragma once\n",
    "#include <bits/stdc++.h>\n",
    "using namespace std;\n",
    '#include "../template/const.hpp"\n'
]

class CodeReader():
    def __init__(self,path):
        self.path = pathlib.Path(path)
        self.visited = set()
        self.cwd = None
        self.code = []
    
    def readfile(self):
        self._readfile_recursively(self.path.resolve())
        return self.code
    
    def _remove_include(self,include_sentence):
        return include_sentence.removeprefix("#include").replace('"','').strip()
    
    def _get_next_path(self,current_file,next_file):
        next_path = current_file.parent / next_file 
        return next_path.resolve()
    
    def _readfile_recursively(self,current_path):
        self.visited.add(current_path)
        with open(current_path,mode = "r") as f:
            for line in f:
                if line in IGNORE_SENTENCE:
                    continue
                elif line.startswith("#include"):
                    next_path = self._get_next_path(current_path,self._remove_include(line))
                    if next_path not in self.visited:
                        self._readfile_recursively(next_path)
                else:
                    self.code.append(line.rstrip())

def create_snippet(path,prefix,description=""):
    code_reader = CodeReader(path)
    snippet_body = code_reader.readfile()
    return Snippet(
        name = path,
        prefix = prefix,
        body = snippet_body,
        description = description
    )

def output_snippets(snippets):
    if not os.path.exists(".vscode"):
        os.mkdir(".vscode")
    with open(".vscode/procon.code-snippets",mode = "w") as f:
        f.write("{")
        for snippet in snippets:
            f.write(snippet.to_json())
            f.write(",")
        f.write("}")

IGNORE_DIR = [
    ".git",
    ".github",
    ".verify-helper",
    ".vscode",
    "ac-library",
    "template",
    "test",
    "testa",
    "testb",
    "testc",
    "testd",
    "teste",
    "testf",
    "testg",
    "testh",
    "venv",
    "tools",
    "result"
]

def main():
    snippets = []

    cwd_path = "./"
    for dir in os.listdir(cwd_path):
        dir_path = os.path.join(cwd_path,dir) 
        if ( not os.path.isdir(dir_path) ) or ( dir in IGNORE_DIR ):
            continue
        for file in os.listdir(dir_path):
            file_path = os.path.join(dir_path,file)
            prefix = file[:-4] # file = "a.cpp"
            snippets.append(create_snippet(file_path,f"snp {prefix}"))

    output_snippets(snippets)

if __name__ == "__main__":
    main()