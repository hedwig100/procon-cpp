import os,subprocess,argparse,datetime

def cmd(cmd_str,get_stdout = False):
    if get_stdout:
        return subprocess.check_output(cmd_str,shell=True)
    else:
        return subprocess.run(cmd_str,shell=True)

class ResultLogger():
    def __init__(self,is_test):
        self.is_test = is_test 

    def log(self,scores,dirname):
        if not self.is_test:
            os.mkdir(dirname)
            self._log_score(scores,dirname)
            self._log_src(dirname)
        print(scores)
        print(self._mean(scores))

    def _log_score(self,scores, dirname):
        with open(f"{dirname}/res.txt",mode = "w") as f:
            for i,s in enumerate(scores):
                print(f"{i},{s}",file=f)

    def _log_src(self,dirname):
        cmd(f"cp main.cpp {dirname}/main.cpp")
    
    def _mean(self,scores):
        m = 0
        for s in scores:
            m += s 
        return m/len(scores)

def runner(case_id):
    cmd(f"./main.o < tools/in/{case_id:04}.txt > tools/out/{case_id:04}.txt")
    pwd = os.getcwd()
    os.chdir("tools")
    out = cmd(f"cargo run --bin vis in/{case_id:04}.txt out/{case_id:04}.txt",get_stdout=True)
    score = int(out[8:]) # out = "Score = 10902"
    os.chdir(pwd)
    return score

def main(args):
    cmd("make main.o")

    scores = []
    for i in range(args.number):
        scores.append(runner(i))
    
    dirname = f"result/{datetime.datetime.now().isoformat()}"
    logger = ResultLogger(args.test)
    logger.log(scores,dirname)

    cmd(f"open {os.getcwd()}/tools/vis.html")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Marathon Runner')
    parser.add_argument('--number','-n',type=int,help='number of test cases')
    parser.add_argument('--test','-t',action='store_true',help='if --test is set,the result is not recorded.')
    args = parser.parse_args()
    main(args)
