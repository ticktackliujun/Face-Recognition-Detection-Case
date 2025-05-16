//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
//string path = "D:/opencv_tutorial_data-master/opencv_tutorial_data-master/models/face_detector/";
//
//int main(int argc, char** argv)
//{
//    string model_path = path + "opencv_face_detector_uint8.pb";
//    string file_path = path + "opencv_face_detector.pbtxt";
//
//    //��ȡģ������ļ�
//    cv::dnn::Net net = cv::dnn::readNetFromTensorflow(model_path, file_path);
//
//    VideoCapture cap(0);
//
//    Mat frame;
//    while (true)
//    {
//        cap.read(frame);
//        //���������׼mat��ʽ
//        if (frame.empty())
//        {
//            break;
//        }
//        Mat blob = cv::dnn::blobFromImage(frame, 1.0, Size(300, 300), Scalar(104, 177, 123), false, false);
//
//        //��������
//        net.setInput(blob);
//
//        //����
//        Mat probs = net.forward();
//
//        //1x1xNx7,�ĸ���������һ���Ǵ�С��������N�����Ŷ�,���ĸ�
//        Mat detectMat(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
//
//        for (int row = 0; row < detectMat.rows; row++)
//        {
//            float conf = detectMat.at<float>(row, 2);
//            if (conf > 0.5)
//            {
//                float x1 = detectMat.at<float>(row, 3) * frame.cols;
//                float y1 = detectMat.at<float>(row, 4) * frame.rows;
//                float x2 = detectMat.at<float>(row, 5) * frame.cols;
//                float y2 = detectMat.at<float>(row, 6) * frame.rows;
//                Rect box(x1, y1, x2 - x1, y2 - y1);
//                rectangle(frame, box, Scalar(0, 0, 255), 2, 8);
//
//                // �ھ��ο��Ա���ʾ���Ŷ�
//                string confidence = " " + format("confidence:%.2f", conf); // ��ʽ����ƴ�����Ŷ��ַ���
//
//                putText(frame, confidence, Point(x1, y1 - 10), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(0, 0, 255), 2);
//            }
//        }
//
//        imshow("Opencv DNN���������ʾ", frame);
//        char c = waitKey(1);
//        if (c == 27)  // �� 'ESC' ���˳�
//        {
//            break;
//        }
//    }
//    waitKey(0);
//    destroyAllWindows();
//    return 0;
//}
