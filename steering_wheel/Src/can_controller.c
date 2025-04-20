#include "can_controller.h"

CAN_TxHeaderTypeDef tx_header;
CAN_RxHeaderTypeDef rx_header;

uint8_t rx_data[8];
uint8_t tx_data;

uint32_t tx_mailbox;

HAL_StatusTypeDef CAN_Init(CAN_HandleTypeDef *hcan) {

  tx_header.IDE = CAN_ID_STD;
  tx_header.RTR = CAN_RTR_DATA;

  HAL_CAN_Start(hcan);
  HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}

HAL_StatusTypeDef CAN_FilterConfig(CAN_HandleTypeDef *hcan) {

  CAN_FilterTypeDef filterConfig;

  filterConfig.FilterBank = 0;
  filterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
  filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

  filterConfig.FilterIdHigh =
      (CAN_ID_IS_EMERGENCY << STANDARD_CAN_ID_BIT_SHIFT); //>> 16) & 0xFFFF;
  filterConfig.FilterIdLow = 0;
      //(CAN_ID_IS_EMERGENCY << STANDARD_CAN_ID_BIT_SHIFT) & 0xFFFF;

  filterConfig.FilterMaskIdHigh =
      (CAN_ID_VEHICLE_SPEED << STANDARD_CAN_ID_BIT_SHIFT); //>> 16) & 0xFFFF;
  filterConfig.FilterMaskIdLow = 0;
      //(CAN_ID_VEHICLE_SPEED << STANDARD_CAN_ID_BIT_SHIFT) & 0xFFFF;

  filterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
  filterConfig.FilterActivation = ENABLE;
  filterConfig.SlaveStartFilterBank = 14;

  if (HAL_CAN_ConfigFilter(hcan, &filterConfig) != HAL_OK)
    return HAL_ERROR;

  return HAL_OK;
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {

  if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data) == HAL_OK) {
    if (rx_header.IDE == CAN_ID_STD) {
      if (rx_header.StdId == CAN_ID_IS_EMERGENCY) {

      } else if (rx_header.StdId == CAN_ID_VEHICLE_SPEED) {
        
      }
    }
  }
}

void CAN_SendMessage(uint16_t std_id, uint8_t *data, uint8_t len) {

  tx_header.DLC = len;
  tx_header.StdId = std_id;

  HAL_CAN_AddTxMessage(&hcan1, &tx_header, data, &tx_mailbox);
}
