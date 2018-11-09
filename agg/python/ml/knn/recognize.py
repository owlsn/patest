# coding = utf-8
import os
import numpy as np
from sklearn.neighbors import KNeighborsClassifier as kNN

# 处理文件数据
def formatData(dir):
    digits = []
    data = []
    for file in dir:
        filePath = os.path.join(trainPath, file)
        digits.append(int(file.split('_')[0]))
        with open(filePath) as f:
            digit = []
            for line in f.readlines():
                digit += list(line.strip())
            f.close()
            data.append(digit)
        pass
    return data, digits
    pass

if __name__ == '__main__':
    trainPath = os.path.abspath('trainingDigits')
    testPath = os.path.abspath('testDigits')
    trainDir = os.listdir(trainPath)
    testDir = os.listdir(testPath)
    trainData, trainDigits = formatData(trainDir)
    neigh = kNN(n_neighbors = 3, algorithm='auto')
    neigh.fit(np.array(np.float64(trainData)), np.array(trainDigits))
    errorCount = 0.0
    testData, testDigits = formatData(testDir)
    result = neigh.predict(np.array(np.float64(testData)))
    count = result.shape[0]
    for i in result:
        print("预测结果为:{},实际结果为:{}".format(result[i], testDigits[i]))
        if result[i] != testDigits[i]:
            errorCount += 1.0
        pass
    print("错误数:{},总数:{},错误率为:{:.2f}%".format(errorCount, count, errorCount / float(count) * 100))
    pass