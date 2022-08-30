import { Module } from "@nestjs/common";
import { SecondAuthService } from "./second-auth.service";
import { SecondAuthController } from "./second-auth.controller";
import { TypeOrmModule } from "@nestjs/typeorm";
import { SecondAuthRepository } from "./second-auth.repository";
import { UserRepository } from "src/user/user.repository";

@Module({
  imports: [
    TypeOrmModule.forFeature([SecondAuthRepository, UserRepository]),
    UserRepository,
  ],
  providers: [SecondAuthService],
  controllers: [SecondAuthController],
  exports: [SecondAuthService],
})
export class SecondAuthModule {}
