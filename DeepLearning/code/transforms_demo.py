from torch.utils.tensorboard import SummaryWriter
from torchvision import transforms
from PIL import Image
img_path='../Dataset_1/train/ants/0013035.jpg'
img_PIL = Image.open(img_path)
to_tensor = transforms.ToTensor()
img_tensor = to_tensor(img_PIL)
writer=SummaryWriter("logs")
writer.add_image('testPic',img_tensor,3)
writer.close()
