# PBL2
15/10/2021
- Chỉnh sửa lại tên, đổi tất cả sanpham thành maytinh
- chuyển các mảng đối tượng thành vector
- Tách hàm createSanPham thành createSanPham và WriteToFileMayTinh(ghi vào file).
- Hàm createSanPham đầu tiên sẽ tăng kích thước vector (đang xem xét cách tăng) -> nhập đối tượng cuối cùng trong vector -> ghi đối tượng đó vào file -> tăng count lên 1
- Trong hàm ReadSanPham, thực hiện kiểm tra biến đầu tiên của mỗi hàng, nếu biến đó có độ dài <=1 thì break hoặc continue => kết thúc đọc file khi gặp dòng trống (mục đích là vì trước eof/end of file có thể có nhiều dòng trống khiến cho việc đọc dữ liệu bị lỗi)
- Thêm hàm sửa dữ liệu và xóa dữ liệu. PP như trong báo cáo.

22/10/2021
- Làm menu thêm, sửa, xóa thông tin
- gộp file kho vào file maytinh

23/10/2021
- gộp file thongtinhoadon vào hoadon
- đổi tên các hàm create thành add (createmaytinh -> addmaytinh)
- trong menu chỉnh sửa thông tin và xóa thông tin, bỏ mục xóa thông tin kho và chỉnh sửa thông tin kho (vì đã gộp kho vs maytinh,sau sẽ tạo thành 1 chức năng riêng là nhập hàng về)
- thêm hàm show1maytinh (tương tự hàm showmaytinh nhưng truyền thêm mamay vào, chỉ in ra thông tin của 1 máy tính) -> cần làm tương tự cho các class khác
- tạm hoàn thiện hàm editmaytinh (thiếu phần xác nhận chỉnh sửa thông tin)
- hàm deletemaytinh thiếu phần xác nhận
- bỏ hàm thêm hóa đơn (tách ra thành chức năng lập hóa đơn)
