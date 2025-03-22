import torchvision
from torch import nn
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter
from torchvision.transforms import transforms

#导入并打包数据集
dataset=torchvision.datasets.CIFAR10("../Dataset_2",train=False,download=True,transform=transforms.Compose([transforms.ToTensor()]))
data_loader=DataLoader(dataset,64,shuffle=False,num_workers=0,drop_last=True)
class MyNL(nn.Module):
    def __init__(self):
        super(MyNL, self).__init__()
        self.Relu = nn.ReLU()
        self.sigmoid = nn.Sigmoid()
    def forward(self,x):
        output=self.sigmoid(x)
        # output=self.Relu(x)
        return output
my_NL=MyNL()
steps=0
writer=SummaryWriter("../logs")
for data in data_loader:
    imgs,targets=data
    outputs=my_NL(imgs)
    writer.add_images('output_NL',outputs,steps)
    steps+=1
writer.close()