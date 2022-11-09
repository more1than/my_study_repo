import ssl
from qcloudsms_py import SmsMultiSender, SmsSingleSender
from qcloudsms_py.httpclient import HTTPError


def send_sms_single(phone_num, template_id, template_param_list):
    """
    单条发送短信
    :param phone_num: 手机号
    :param template_id: 腾讯云短信模板ID
    :param template_param_list: 短信模板所需参数列表，例如【验证码：{1}， 描述：{2}】 ，则传递参数[888, 666]按顺序格式化模板
    :return:
    """
    appid = 11111  # 自己的应用ID
    appkey = "dawdawd"  # 自己的key
    sms_sign = "xxx"  # 腾讯云创建签名时填写的签名内容

    sender = SmsSingleSender(appid, appkey)
    try:
        response = sender.send_with_param(86, phone_num, template_id, template_param_list, sign=sms_sign)
    except HTTPError as e:
        response = {"result": 1000, "errmsg": "网络异常，发送失败,错误信息为：{}".format(e)}
    return response


def send_sms_multi(phone_num_list, template_id, param_list):
    """
    批量发送短信
    :param phone_num_list: 手机号列表
    :param template_id: 腾讯云短信模板ID
    :param param_list: 短信模板所需参数列表，例如【验证码：{1}， 描述：{2}】 ，则传递参数[888, 666]按顺序格式化模板
    :return:
    """
    appid = 11111  # 自己的应用ID
    appkey = "dawdawd"  # 自己的key
    sms_sign = "xxx"  # 腾讯云创建签名时填写的签名内容

    sender = SmsMultiSender(appid, appkey)
    try:
        response = sender.send_with_param(86, phone_num_list, template_id, param_list, sign=sms_sign)
    except HTTPError as e:
        response = {"result": 1000, "errmsg": "网络异常，发送失败,错误信息为：{}".format(e)}
    return response


if __name__ == '__main__':
    result1 = send_sms_single("188xxxxxx", 523321, [666, ])
    print(result1)

    result2 = send_sms_multi(["188xxxxxx", "133xxxxxx"], 523321, [666, ])
    print(result2)
