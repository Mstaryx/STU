import torchvision
import torchvision.transforms
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter
from torchvision import transforms
#测试数据集
test_data=torchvision.datasets.CIFAR10("../Dataset_2",train=False,download=True,transform=transforms.Compose([transforms.ToTensor()]))
test_loader=DataLoader(test_data,batch_size=64,shuffle=True,num_workers=0,drop_last=True)
img,target=test_data[0]
writer=SummaryWriter('../logs')
step=0
for data in test_loader:
    imgs,targets=data
    writer.add_images('datas',imgs,step)
    step+=1
writer.close()