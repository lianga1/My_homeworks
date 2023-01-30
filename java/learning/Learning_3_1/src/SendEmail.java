import java.security.GeneralSecurityException;
import java.util.Properties;
import javax.mail.*;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import com.sun.mail.util.MailSSLSocketFactory;

public class SendEmail
{
    public static void main(String [] args) throws GeneralSecurityException, MessagingException {
        // 收件人电子邮箱
        String to = "21307140019@m.fudan.edu.cn";

        // 发件人电子邮箱
        String from = "1838169875@qq.com";

        // 指定发送邮件的主机为 smtp.qq.com
        String host = "smtp.qq.com";  //QQ 邮件服务器

        // 获取系统属性
        Properties properties = new Properties();
//设置邮件服务器
        properties.setProperty("mail.host", "smtp.qq.com");
// 邮件发送协议
        properties.setProperty("mail.transport.protocol", "smtp");

        // 设置邮件服务器


        properties.put("mail.smtp.auth", "true");
        MailSSLSocketFactory sf = new MailSSLSocketFactory();
        sf.setTrustAllHosts(true);
        properties.put("mail.smtp.ssl.enable", "true");
        properties.put("mail.smtp.ssl.socketFactory", sf);
        // 获取默认session对象
        Session session = Session.getDefaultInstance(properties,new Authenticator(){
            public PasswordAuthentication getPasswordAuthentication()
            {
                return new PasswordAuthentication("1838169875@qq.com", "ocxmkfnylqjtcddf"); //发件人邮件用户名、密码
            }
        });
        System.out.println("0");
        //2、通过session获取transport对象
        Transport transport = session.getTransport();
        System.out.println("transport:");
        //3、通过transport对象设置发件账号和授权码连接邮箱服务器
        transport.connect("smtp.qq.com", "1838169875@qq.com", "ocxmkfnylqjtcddf");
        try{
            // 创建默认的 MimeMessage 对象
            MimeMessage message = new MimeMessage(session);
            System.out.println("1");
            // Set From: 头部头字段
            message.setFrom(new InternetAddress(from));
            System.out.println("2");
            // Set To: 头部头字段
            message.addRecipient(Message.RecipientType.TO, new InternetAddress(to));
            System.out.println("3");
            // Set Subject: 头部头字段
            message.setSubject("This is the Subject Line!");
            System.out.println("4");
            // 设置消息体
            message.setText("This is actual message");
            System.out.println("5");
            // 发送消息
            message.setRecipients(Message.RecipientType.TO, "21307140019@m.fudan.edu.cn");
//发送
            transport.sendMessage(message, message.getAllRecipients());
            //6、关闭连接
            transport.close();
            System.out.println("Sent message successfully....from Zion");
        }catch (MessagingException mex) {
            mex.printStackTrace();
        }
    }
}