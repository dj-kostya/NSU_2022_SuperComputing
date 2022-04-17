import subprocess
import json

command = '/home/konstantin/projects/NSU_2022_SuperComputing/Task1/cmake-build-debug/Task1 {num_threads}'

test_type = 'no_omp'
resolution = '1920x1080x10'
results = dict()
if test_type != 'no_omp':
    for i in [1, 2, 4, 8, 16]:
        results[i] = []
        cur_com = command.format(num_threads=i).split()
        print(f'Run {cur_com} ')
        for _ in range(5):
            process = subprocess.Popen(cur_com, stdout=subprocess.PIPE)
            output, error = process.communicate()
            time = float(output.decode("utf-8").strip().replace('Time = ', ''))
            results[i].append(time)
            print('Time: ', time)
else:
    results[1] = []
    cur_com = command.format(num_threads=1).split()
    print(f'Run {cur_com} ')
    for _ in range(5):
        process = subprocess.Popen(cur_com, stdout=subprocess.PIPE)
        output, error = process.communicate()
        time = float(output.decode("utf-8").strip().replace('Time = ', ''))
        results[1].append(time)
        print('Time: ', time)


with open(f'results_{test_type}_{resolution}.json', 'w') as f:
    json.dump(results, f, ensure_ascii=False)
