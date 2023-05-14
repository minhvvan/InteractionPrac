# InteractionPrac
> Player와의 Interaction을 구현할 수 있는 Component를 제작한다.

## Tech Stack
<p>
<img src="https://img.shields.io/badge/unrealengine-0E1128?style=for-the-badge&logo=unrealengine&logoColor=white">
<img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">
</ p>

## 구현 목록
### 빗자루
![빗자루](https://github.com/minhvvan/InteractionPrac/assets/59609086/b068996b-99e8-482f-ad7e-ce06fe971aa3)
- Interaction이 가능한 범위(Trigger)에 Player가 접근시 Interaction을 위한 UI를 표시한다.
- 정해진 Interaction Key(E)를 입력하면 물체에 알맞는 상호작용을 실행한다.
- 빗자루를 타는 Animation을 실행한 후 Movemetn Mode를 Flying으로 변경한다.
- 정해진 Key(Space: Up, Shift: Down)를 이용하여 동작할 수 있게 한다.

### 자동차
![자동차](https://github.com/minhvvan/InteractionPrac/assets/59609086/83806d07-9c71-4418-ab96-79575ed318e4)
- Interaction이 가능한 범위(Trigger)에 Player가 접근시 Interaction을 위한 UI를 표시한다.
- 정해진 Interaction Key(E)를 클릭하면 물체에 알맞는 상호작용을 실행한다.
- Interation이 시작되면 Player를 숨기고(Visible = false) 제어권을 자동차(Actor)에게 양도한다.
- 상호작용 종료키(E)를 입력하면 자동차(Actor)가 있는 위치로 Player를 이동 시킨 후 표시한다(Visible = true).
