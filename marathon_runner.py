import os,subprocess,argparse

def cmd(cmd_str):
    subprocess.run(cmd_str,shell=True)

def runner(case_id):
    cmd(f"./main.o < tools/in/{case_id:04}.txt > tools/out/{case_id:04}.txt")
    pwd = os.getcwd()
    os.chdir("tools")
    cmd(f"cargo run --bin vis in/{case_id:04}.txt out/{case_id:04}.txt")
    os.chdir(pwd)

def main(args):
    cmd("make main.o")
    for i in range(args.number):
        runner(i)
    cmd(f"open {os.getcwd()}/tools/vis.html")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Marathon Runner')
    parser.add_argument('--number','-n',type=int,help='number of test cases')
    args = parser.parse_args()
    main(args)
