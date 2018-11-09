# coding = utf-8
import os
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines

def classify(testData, trainData, datingLabels, k):
    vec = trainData.shape[0]
    dmt = np.tile(testData, (vec, 1)) - trainData
    dmt = dmt ** 2
    sumDmt = dmt.sum(axis=1)
    sumDmt = sumDmt ** 0.5
    keySort = sumDmt.argsort()
    result = {}
    for i in range(k):
        vlabels = datingLabels[keySort[i]]
        result[vlabels] = result.get(vlabels, 0) + 1
    # 返回k个中出现次数最多的
    sortResult = sorted(result.items(), key=lambda key: key[1], reverse=True)
    return sortResult[0][0]
    pass

def parseFile(filePath):
    originData = []
    datingLabels = []
    labelsDict = {"didntLike": 1, "smallDoses": 2, "largeDoses": 3}
    with open(filePath) as f:
        for line in f:
            line = line.strip().split('\t')
            originData.append(np.float64(line[0:3]))
            datingLabels.append(labelsDict[line[3]])
            pass
    # 数据归一化
    npOriginData = np.array(originData)
    minimum = npOriginData.min(0)
    maximum = npOriginData.max(0)
    ranges = maximum - minimum
    normData = npOriginData - minimum
    normData = normData / ranges
    return normData, datingLabels
    pass

def show(normData, datingLabels):
    fig, axs = plt.subplots(ncols=2, nrows=2, figsize=(15, 8))
    colorDict = {1: 'blue', 2: 'red', 3: 'green'}
    labelColors = list(map(lambda color: colorDict[color], datingLabels))
    axs[0][0].scatter(x=normData[:, 0], y=normData[:, 1], color=labelColors, s=10, alpha=0.5)
    titleText00 = axs[0][0].set_title('fly miles:game hours')
    xLabel00 = axs[0][0].set_xlabel('fly miles')
    yLabel00 = axs[0][0].set_ylabel('game hours')
    plt.setp(titleText00, color='red')
    plt.setp(xLabel00, color='red')
    plt.setp(yLabel00, color='red')
    axs[0][1].scatter(x=normData[:, 0], y=normData[:, 2], color=labelColors, s=10, alpha=0.5)
    titleText01 = axs[0][1].set_title('fly miles:ice cream volume')
    xLabel01 = axs[0][1].set_xlabel('fly miles')
    yLabel01 = axs[0][1].set_ylabel('ice cream volume')
    plt.setp(titleText00, color='red')
    plt.setp(xLabel01, color='red')
    plt.setp(yLabel01, color='red')
    axs[1][0].scatter(x=normData[:, 1], y=normData[:, 2], color=labelColors, s=10, alpha=0.5)
    titleText10 = axs[1][0].set_title('game hours:ice cream volume')
    xLabel10 = axs[1][0].set_xlabel('game hours')
    yLabel10 = axs[1][0].set_ylabel('ice cream volume')
    plt.setp(titleText10, color='red')
    plt.setp(xLabel10, color='red')
    plt.setp(yLabel10, color='red')

    didntLike = mlines.Line2D([], [], color='blue', marker='.',
                              markersize=6, label='didntLike')
    smallDoses = mlines.Line2D([], [], color='red', marker='.',
                               markersize=6, label='smallDoses')
    largeDoses = mlines.Line2D([], [], color='green', marker='.',
                               markersize=6, label='largeDoses')
    # 添加图例
    axs[0][0].legend(handles=[didntLike, smallDoses, largeDoses])
    axs[0][1].legend(handles=[didntLike, smallDoses, largeDoses])
    axs[1][0].legend(handles=[didntLike, smallDoses, largeDoses])
    plt.show()
    pass

if __name__ == '__main__':
    filePath = os.path.abspath('datingTestSet.txt')
    # 获取原始数据
    # originData:list,
    # datingLabels:list
    normData, datingLabels = parseFile(filePath)
    # 数据可视化
    # show(normData, datingLabels)
    length = normData.shape[0]
    radio = 0.1
    num = int(radio * length)
    errorCount = 0.0
    for i in range(num):
        classResult = classify(normData[i], normData[num: length], datingLabels[num: length], 4)
        print("分类结果为:{},实际结果为{}".format(classResult, datingLabels[i]))
        if classResult != datingLabels[i]:
            errorCount += 1.0
        pass
    print("错误率为:{:.2f}%".format(errorCount / float(num) * 100))
    pass